const WebSocket = require('ws');
const server = new WebSocket.Server({ port: 8080 });
server.on('connection', ws => {
    console.log('Client connected');
    ws.on('message', message => {
        console.log(`Received: ${message}`);
        // Echo the received message back to the client
        ws.send(message);
    });
    ws.on('close', () => {
        console.log('Client disconnected');
    });
});

console.log('WebSocket server is running on ws://localhost:8080');

 
