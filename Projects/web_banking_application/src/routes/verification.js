const express = require('express');
const { model } = require('mongoose');
const collection = require('../config');
const jwt = require('jsonwebtoken');
const router = express.Router();

const JWT_SECRET = 'my_project_not_safty';

router.get("/", async (req, res, next) => {

    const token = req.query.token;

    try {
        const decoded = jwt.verify(token, JWT_SECRET);
        const userEmail = decoded.email;

        const result = await collection.updateOne({ email: userEmail }, { $set: { status: 'ready' } });

        if (result.matchedCount === 1) {
            console.log('Successfully updated the document.');
            res.send('Email verified successfully.');
        } else {
            console.log('No document matches the provided email.');
            res.status(404).send('User not found');
        }
        res.render("verification");
    } catch (error) {
        console.error('Error during verification:', error);
        error.status = 400;
        if(error.name === 'TokenExpiredError')
        {
            error.message = 'Verification link has expired. Please sign up again.';
        }
        else
        {
            error.message = 'Invalid verification link.';
        }
        next(error);
    }
});

module.exports = router;