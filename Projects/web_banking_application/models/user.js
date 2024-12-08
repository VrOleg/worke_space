const mongoose = require('mongoose');
const { stringify } = require('querystring');

const userSchema = new mongoose.Schema({
    email: {
        type: String,
        required: true,
        unique: true,
        lowercase: true,
        trim: true,
        validate: {
            validator: function (value) {
                return /^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(value);
            },
            message: 'Invalid email address format',
        },
    },
    password: {
        type: String,
        required: true,
        minlength: 6
    },
    phone: {
        type: String,
        required: false,
        match: [/^\d{10}$/, 'Please use a valid phone number']
    },
    status: {
        type: String,
        required: true,
        default: 'unConfirmed',
    }
    },{
        timestamps: true   
    });

    //create user model
    const User = mongoose.model('User', userSchema);

    //export user model
    module.exports = User;