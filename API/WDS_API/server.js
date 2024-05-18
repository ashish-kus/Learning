const express = require('express')
const mongoose = require('mongoose')
const app = express();
const PORT = 3000;

app.listen(
  PORT,
  () => console.log("server started at 3000")
)
