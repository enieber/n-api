const addon = require('bindings')('hello');

console.log(addon.add(1, 1)); // 'world'
