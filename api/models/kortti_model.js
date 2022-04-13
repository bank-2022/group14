const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;

const kortti = {
  getById: function(id, callback) {
    return db.query('select * from kortti where idKortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(kortti, callback) {
      bcrypt.hash(kortti.pin, saltRounds, function(err, hash){
        return db.query(
            'insert into kortti (korttinumero,idKortti,idAsiakas,idTili,pin) values(?,?,?,?,?)',
            [kortti.korttinumero, kortti.idKortti, kortti.idAsiakas, kortti.idTili, hash],
            callback
          );          
      })
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where idKortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    bcrypt.hash(kortti.pin, saltRounds, function(err, hash){
      return db.query(
          'update kortti set idKortti=?, korttinumero=?,idAsiakas=?, idTili=?, pin=? WHERE idKortti=?',
          [kortti.idKortti, kortti.korttinumero, kortti.idAsiakas, kortti.idTili, hash, id],
          callback
        );          
    })
}
};
module.exports = kortti;