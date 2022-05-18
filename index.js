const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline')
const fs = require('fs');

const parser = new ReadlineParser();

let portNum = process.argv[2];
let SSN = process.argv[3];
let portName = 'COM' + portNum;

let myPort = new SerialPort({
    path: portName,
    baudRate: 9600,
});

myPort.pipe(parser);

let ecg = [];

function readData(){
    console.log('Getting ready to scan...');
    console.log('Scanning...');
    parser.on('data', (data) => {
        if (data.indexOf('Beginning Program') > -1)
        {
            ecg.push(0);
        }else{
            ecg.push(data);
        }
    });
}

function logECG() {
    let date = new Date();
    let filename = _dirname + '\\results\\' + SSN + '' + date.getFullYear() + '-' + date.getMonth() + '-' + date.getDay() + '_' + date.getHours() + '-' + date.getMinutes() + '-' + date.getSeconds() + '.txt';
    let text = ecg.join('\n');
    try{
        fs.writeFileSync(filename, text);
        console.log("Scanned! Thank u for more info!");
    } catch (e) {
        console.log(e);
    }
}

readData();
setTimeout(logECG, 15000);