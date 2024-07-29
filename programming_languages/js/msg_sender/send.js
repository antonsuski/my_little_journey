function log(msg) { console.log("[LOG]:" + msg); }
function send(msg){log("sending messgae:" + msg)};

let default_entity = {id : 0, status : 0, g : {id : 0, status : 0, state : 0}};

send(default_entity);
