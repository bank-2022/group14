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
            'insert into kortti (idKortti,korttinumero,pin,idAsiakas,idTili) values(?,?,?,?,?)',
            [kortti.idKortti, kortti.korttinumero, hash, kortti.idAsiakas, kortti.idTili],
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
          'update kortti set idKortti=?, korttinumero=?, pin=?,idAsiakas=?, idTili=? WHERE idKortti=?',
          [kortti.idKortti, kortti.korttinumero, hash, kortti.idAsiakas, kortti.idTili,  id],
          callback
        );          
    })
}
};
module.exports = kortti;