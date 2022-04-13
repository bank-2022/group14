var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const basicAuth = require('express-basic-auth');
const helmet = require('helmet');
const cors = require('cors');


const asiakasRouter = require('./routes/asiakas');
const loginRouter = require('./routes/login');
const tiliRouter = require('./routes/tili');
const korttiRouter = require('./routes/kortti');
const tilitapahtumatRouter = require('./routes/tilitapahtumat');
const userRouter = require('./routes/user');


var app = express();

//router.use(basicAuth({users: { 'admin': '1234' }}))

app.use(helmet());
app.use(cors());
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/tili', tiliRouter)
app.use('/asiakas', asiakasRouter)
app.use('/login', loginRouter)
app.use('/kortti', korttiRouter)
app.use('/tilitapahtumat', tilitapahtumatRouter)
app.use('/user', userRouter)


app.use(basicAuth({users: { 'admin': '1234' }}))

module.exports = app;
