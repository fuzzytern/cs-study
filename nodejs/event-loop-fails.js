const EventEmitter = require('events').EventEmitter;
const util = require('util');

class ProgressBar extends EventEmitter {
  constructor(){
    super();
    this.interrupted = false;
  }

  updateBar(){
    // Writes one sign '=' to the standard output 
    process.stdout.write('='); 
  }

  interrupt(){
    // Sets the value of `interrupt` to `true`
    this.emit('interrupt');
    this.interrupted = true;
  }

  run(){
    do{
      setTimeout(this.updateBar,1000);
    } while(!this.interrupted); 
  }
}

let bar = new ProgressBar;

bar.on('interrupt', ()=>{
  console.log("Process interrupted");
}); 
bar.interrupt();
// setTimeout(bar.interrupt, 2000); // FIXME figure out why it crashes: `this.emit` is not a function
// bar.run(); // FIXME the code without this line should work return "Process interrupted"...
