const express = require('express');
const app = express();
const PORT = 8080;
const Events = require("./data.json");

app.use(express.json());
app.listen(
  PORT,
  () => console.log(`Server is alive on https://localhost:${PORT}`)
);

app.get(
  '/api/events',
  (req, res) => {
    res.status(200).send(Events);
  }
);


app.get(
  '/api/events/:id',
  (req, res) => {
    const id = req.params.id;
    const event = Events[id];
    if (event) {
      return res.status(200).send(event);
    } else {
      return res.status(404).send("Event not found");
    }
  }
);

