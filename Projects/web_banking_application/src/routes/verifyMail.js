const jwt = require('jsonwebtoken');
const nodemailer = require('nodemailer');

//jwt secret 
const JWT_SECRET = 'my_project_not_safty';


//create a transporter object
const transporter = nodemailer.createTransport({
    service: 'gmail',
    auth: {
        user: 'oleg.vragov1987@gmail.com',
        pass: 'vwsp blil ifmq ubyx'
    }
});

const generateVerificationToken = (email) => {
    return jwt.sign({email}, JWT_SECRET, {expiresIn: '24h'});
}

//send a verification email
const sendVerificationEmail = async (toEmail, verificationLink) => {
    const mailOptions = {
        from: '"WEB Bank App" <oleg.vragov1987@gmail.com>',
        to: toEmail,
        subject: 'Verify your email',
        html:`
            <p>Hello,</p>
            <p>Thank you for registering with us, Please click the link below to verify your email:</p>
            <a href="${verificationLink}">Verify Email</a>
            <p>If you didn't request this, please ignore this email.</p>
            `
    };

    try {
        const info = await transporter.sendMail(mailOptions);
        console.log('Email sent: ' + info.response);
    } catch (error)
    {
        console.error('Error sending email: ' + error);
    }
};

module.exports = {sendVerificationEmail, generateVerificationToken };