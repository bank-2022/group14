const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'https://thoon.feralhosting.com/tinosaurus',
  user: 'netuser',
  password: 'netpass',
  database: 'banksimul'
});
module.exports = connection;
