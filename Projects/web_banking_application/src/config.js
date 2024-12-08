const mongoose = require("mongoose");
const connection = mongoose.connect("mongodb://localhost:27017/Bank_Web_App");
const userModel = require("../models/user");

//check database connected or not
 connection.then(() => {
    console.log("Database connected Successfully");
 })
 .catch(() => {
    console.log("Database cannot be connected");
 })


module.exports = userModel;