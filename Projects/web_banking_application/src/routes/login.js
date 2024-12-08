const express = require('express');
const router = express.Router();
const collection = require("../config");
const bcrypt = require('bcrypt');

router.get("/", (req, res) => {
    res.render("login", {error: null});
});

//Login user
router.post("/", async (req, res, next) => {
    try {
        console.log("Request Body: ", req.body);

        if (!req.body.username || !req.body.password) {
            console.log('status:400 -> Username and password are required');
            return res.render("login", {error: "*Username and password are required."});
        }

        const check = await collection.findOne({ email: req.body.username });
        console.log("user: ", check);

        if (!check) {
            return res.render('login', {error: '*Invalid email or password!'});
        }

        if ("unConfirmed" === check.status) {
            console.log('status: 403 -> Please confirm your email to login');
            return res.render('login', {error:'*Please confirm your email to login.'});
        }

        const isPasswordMatch = await bcrypt.compare(req.body.password, check.password);
        console.log('isPasswordMatch = ', isPasswordMatch);
        if (isPasswordMatch) {
           return res.render("home");
        }
        else{
            return res.render('login', {error: '*Invalid email or password!'});
        //    return res.status(401).send("Wrong login data");
        }
    }
    catch (error) {
        console.error("Error during login:", error); 
        next(error);
        // res.status(500).send("An error occurred during login.");
    }
});

module.exports = router;