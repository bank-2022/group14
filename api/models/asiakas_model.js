const db = require('../database');

const asiakas = {
  getById: function(id, callback) {
    return db.query('select * from asiakas where idasiakas=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas', callback);
  },
  add: function(asiakas, callback) {
    return db.query(
      'insert into asiakas (nimi,katuosoite,puhelinnumero,idasiakas) values(?,?,?,?)',
      [asiakas.nimi, asiakas.katuosoite, asiakas.puhelinnumero, asiakas.idasiakas],
      callback
    );
  },
  delete: function(idasiakas, callback) {
    return db.query('delete from asiakas where idasiakas=?', [idasiakas], callback);
  },
  update: function(id, asiakas, callback) {
    return db.query(
      'update asiakas set nimi=?,katuosoite=?, puhelinnumero=? where idasiakas=?',
      [asiakas.nimi, asiakas.katuosoite, asiakas.puhelinnumero, id],
      callback
    );
  }
};
module.exports = asiakas;