const express = require('express');
const path = require('path');
const bcrypt = require('bcrypt');
const collection = require("./config");

const app = express();

//convert data into json format
app.use(express.json());

app.use(express.urlencoded({extended: false}));

//use EJS as the view engine
app.set('view engine', 'ejs');

//static file
app.use(express.static("public"));

app.get("/", (req,res) => {
    res.render("login");
});

app.get("/signup", (req,res) => {
    res.render("signup");
});

//Register User
app.post("/signup", async (req,res) => {
    const data = {
        name: req.body.username,
        password: req.body.password
    }

//check if user exsist
    const existingUser = await collection.findOne({name: data.name});

    if(existingUser)
    {
        res.send("User already exists. Please choose a different username.");
    }
    else
    {
        //hash the password
        const saltRounds = 10;
        const hashedPassword  = await bcrypt.hash(data.password, saltRounds);

        data.password = hashedPassword;

        //insert data to database (mongoDB)
        const userdata = await collection.insertMany(data);
        console.log(userdata);
        res.render("login");
    }
    
});

//Login user
app.post("/login",async (req,res) => {
    try
    {
        const check = await collection.findOne({name: req.body.username});
        const isPasswordMatch = await bcrypt.compare(req.body.password, check.password);

        if(check && isPasswordMatch)
        {
            res.render("home");
        }
        else
        {
            res.send("Wrong login data");
        }
    }
    catch
    {
        res.send("Wrong Details");
    }
});

const port = 5000;
app.listen(port, () => {
    console.log(`Server running on Port: ${port}`);
});