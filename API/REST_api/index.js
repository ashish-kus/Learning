const express = require("express");
// const Events = require("./data.json");
const app = express();
const PORT = 8080;

app.listen(
  PORT,
  () => console.log(`server started at PORT 8080`)
);


app.get(
  "/Events",
  (req, res) => {
    return res.json(Events);
  }
)
