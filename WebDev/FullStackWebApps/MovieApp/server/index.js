require("dotenv").config();
const express = require("express");
const cors = require("cors");
const routes = require("./routes");

const app = express();

app.use(cors());
app.use(express.json());

app.get("/", (req, res) => {
    res.send("Server is running");
});

const PORT = process.env.PORT || 4000;
app.listen(PORT, () => {
    console.log(`Server is listening on port ${PORT}`);
});

const mongoose = require("mongoose");

mongoose.connect(
    `${process.env.MONGODB_CONNECTION_STRING}/${process.env.MONGODB_DATABASE_ID}`,
    {
        useNewUrlParser: true,
        useUnifiedTopology: true,
    }
).then(() => console.log("Connected to MongoDB"))
    .catch((err) => console.error("Error connecting to MongoDB", err));

app.use("/api", routes);
