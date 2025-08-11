const express = require("express");
const app = express();

app.get("/", function (req, res) {
  res.send("Hello People");
});

app.listen(3000);
