const mongoose = require("mongoose");
const connection = mongoose.connect("mongodb://localhost:27017/Bank_Web_App");

//check database connected or not
 connection.then(() => {
    console.log("Database connected Successfully");
 })
 .catch(() => {
    console.log("Database cannot be connected");
 })

 // create a schema
const user = new mongoose.Schema({
    name: {
        type: String,
        required: true
    },
    password: {
        type: String,
        required: true
    }
});

// collaction part (Model)
const collection = new mongoose.model("Users", user);

module.exports = collection;