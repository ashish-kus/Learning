const http = require("http");
const express = require("express")
const path = require("path");
const Server = require("socket.io");
const { Socket } = require("dgram");

const app = express();
const server = http.createServer(app);
const io = new Server(server)

io.on('connnection', (socket) => {
    console.log("New connection to server", socket.id);
});


app.use(express.static(path.resolve("./public")));

app.get('/', (req, res) => {
    return res.sendFile("/public/index.html");
})
server.listen(9000, () => {
    console.log("hello from server at PORT: 9000");
})