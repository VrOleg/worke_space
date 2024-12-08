const express = require('express');
const router = express.Router();
const collection = require("../config");
const bcrypt = require('bcrypt');
const verify = require('./verifyMail');

router.get("/", (req, res) => {
    res.render("signup");
});

//Register User
router.post("/", async (req, res, next) => {
    const data = {
        email: req.body.userEmail,
        password: req.body.password,
        phon: req.body.phon
    }
    
    console.log(data);

    if(!req.body.email)
    {
        return res.render('signup', {errorId: 'error-label-email'});
    }

    if(!req.body.password)
    {
        return res.render('signup', {errorId: 'error-label-password'});
    }

    //check if user exsist
    const existingUser = await collection.findOne({ email: data.email });

    if (existingUser) {
        const error = new Error("User already exists. Please choose a different email.");
        error.status = 400;
        error.link = "/signup";
        return next(error);
    }

    //hash the password
    const saltRounds = 10;
    const hashedPassword = await bcrypt.hash(data.password, saltRounds);

    data.password = hashedPassword;

    //insert data to database (mongoDB)
    const userdata = await collection.insertMany(data);
    console.log(userdata);

    const token = verify.generateVerificationToken(data.email);

    const verificationLink = `${req.protocol}://${req.get('host')}/verification?token=${token}`;
    console.log(verificationLink);
    verify.sendVerificationEmail(data.email, verificationLink);

    console.log('status: 200 ->  Verification email sent');
    res.render("login");

});

function ValidateEmail() {
    const emailInput = document.getElementById('email').value;
    const feadbackElement = document.getElementById('error-label-email');
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

    if(emailRegex.test(emailInput))
    {
        feadbackElement.display = block;
    }
}

module.exports = router;