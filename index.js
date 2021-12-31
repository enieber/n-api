const addon = require('bindings')('hello');
const result = addon.add(1,1);

console.log("result add 1 + 1 = "+result);
console.log(addon.say("world")); 
console.log(addon.say("Enieber"));
