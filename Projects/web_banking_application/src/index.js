const express = require('express');
const path = require('path');

const swaggerUI = require('swagger-ui-express');
const swaggerJsDoc = require('swagger-jsdoc');
const signupRouter = require('./routes/signup');
const loginRouter = require('./routes/login');
const verificationRouter = require('./routes/verification');
const port = 5000;

const options = {
    definition: {
        openapi: "3.0.0",
        info: {
            title: "Bank Web App API",
            version: "1.0.0",
            description: "Simple Bank App"
        },
        servers: [
            {
                url: "http://localhost:5000"
            }
        ]
    },
    apis: ["./routes/*.js"]
}

const specs = swaggerJsDoc(options);

const app = express();

app.use("/api-docs", swaggerUI.serve, swaggerUI.setup(specs));

//convert data into json format
app.use(express.json());

app.use(express.urlencoded({ extended: false }));

//use EJS as the view engine
app.set('view engine', 'ejs');

//static file
app.use(express.static("public"));

app.use('/login', loginRouter);
app.use('/signup', signupRouter);
app.use('/verification', verificationRouter);

app.get("/", (req, res) => {
    res.render("login");
});

app.use((err,req,res,next) => {
    //set error status and message
    const statusCode = err.status || 500;
    const message = err.message || 'Internal Server Error';
    const link = err.link || "/";
    // const linkmessage = err.linkmessage || Go Back To Login;
    const linkmessage = err.linkmessage;
    //Render the error page
    res.status(statusCode).render('error',{
        error: {
            status: statusCode,
            message: message,
        },
        link: link,
        linkMessage: linkmessage
    });
});

app.listen(port, () => {
    console.log(`Server running on Port: ${port}`);
});