import express from "express";
// import bodyParser from "body-parser";
import morgan from "morgan";

const db = [];
const host = "localhost";
const port = 8000;

const app = express();

app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use(morgan("dev"));

app.get("/", (req, res) => {
  const msg = {
    status: 200,
    message: [
      "Hi there👋",
      "Welcome to simple to-do app built using Express server and NodeJs <3",
      "usage: ",
      [
        "GET /          : Home",
        "GET /todo      : Responds with all todo`s",
        "GET /todo:id   : Responds with specific todo with `id`",
        "POST /todo     : Craetes and Responds with new tod; data must be provided for `text`",
      ],
    ],
  };
  res.status(200).json(msg);
});

app.post("/todo", (req, res) => {
  const newTodo = {
    id: Date.now(),
    text: req.body.text,
  };

  db.push(newTodo);

  res.status(201).json(newTodo);
});

app.get("/todo", (req, res) => {
  res.status(200).json(db);
});

app.get("/todo/:id", (req, res) => {
  const todo = db.find((t) => {
    return t.id === +req.params.id;
  });

  res.json({ data: todo });
});

app.listen(port, () => {
  console.log(`Server is running on http://${host}:${port}`);
});
