var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');


//const basicAuth = require('express-basic-auth');
const helmet = require('helmet');
const cors = require('cors');
const jwt = require('jsonwebtoken');

const asiakasRouter = require('./routes/asiakas');
const loginRouter = require('./routes/login');
const tiliRouter = require('./routes/tili');
const korttiRouter = require('./routes/kortti');
const tilitapahtumatRouter = require('./routes/tilitapahtumat');



var app = express();

//router.use(basicAuth({users: { 'admin': '1234' }}))

app.use(helmet());
app.use(cors());
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));


app.use('/login', loginRouter)
app.use(authenticateToken);
app.use('/tili', tiliRouter)
app.use('/asiakas', asiakasRouter)
app.use('/kortti', korttiRouter)
app.use('/tilitapahtumat', tilitapahtumatRouter)



//app.use(basicAuth({users: { 'admin': '1234' }}))

function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
      console.log(err)
  
      if (err) return res.sendStatus(403)
  
      req.user = user
  
      next()
    })
  }

module.exports = app;
