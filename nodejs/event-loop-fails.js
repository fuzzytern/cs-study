// Say we want to write code that prints out "Not ready" every half second and "Finally Ready" after five second.
// A naive implementation that ignore the asynchronous nature of setTimeout and the NodeJS event Loop could look like this:
const EventEmitter = require('events').EventEmitter;
const util = require('util');
const ee = new EventEmitter;

// Let a variable determine indicate whether the timeout is reached
let ready = false;

// After 5 seconds, raise an event that will set that variable to true
setTimeout(() => ee.emit('ready'), 5000);
ee.on('ready', () => {
  ready = true;
});

// while the variable is not set to true, write "Not ready to the output"
while (!ready){ // /!\ This is an infinite loop blocking the Node Event Loop!!!
  setTimeout(console.log,500,"Not ready"); // Also, using setTimeout like so ignores the fact it is asynchronous
}
console.log("Finally Ready"); // This will never be displayed, not even after the timeout

// Instead of line 17 to 20, the following code will not block the event loop. Note the use of recursion
//const printReady = () => {
//  if (!ready)
//    setTimeout( () => {
//        console.log("Not ready");
//        printReady();
//    }, 500);
//  else
//    console.log("Finally Ready");
//}
//printReady();

