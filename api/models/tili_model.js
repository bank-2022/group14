const db = require('../database');

const tili = {
  getById: function(id, callback) {
    return db.query('select * from tili where idTili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tili', callback);
  },
  add: function(tili, callback) {
    return db.query(
      'insert into tili (idTili,Tilinumero,Saldo) values(?,?,?)',
      [tili.idTili, tili.Tilinumero, tili.Saldo],
      callback
    );
  },
  delete: function(idTili, callback) {
    return db.query('delete from tili where idTili=?', [idTili], callback);
  },
  update: function(id, tili, callback) {
    return db.query(
      'update tili set idTili=?,Tilinumero=?, Saldo=? where idTili=?',
      [tili.idTili, tili.Tilinumero, tili.Saldo, id],
      callback
    );
  }
};
module.exports = tili;