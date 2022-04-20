const db = require('../database');

const tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from tilitapahtumat where idtilitapahtumat=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tilitapahtumat', callback);
  },
  add: function(tilitapahtumat, callback) {
    return db.query(
      'insert into tilitapahtumat (idTilitapahtumat,paivamaara,tapahtuma,summa,idKortti,idTili) values(?,?,?,?,?,?)',
      [tilitapahtumat.idTilitapahtumat, tilitapahtumat.paivamaara, tilitapahtumat.tapahtuma, tilitapahtumat.summa, tilitapahtumat.idKortti, tilitapahtumat.idTili],
      callback
    );
  },
  delete: function(idtilitapahtumat, callback) {
    return db.query('delete from tilitapahtumat where idtilitapahtumat=?', [idtilitapahtumat], callback);
  },
  update: function(idtilitapahtumat, tilitapahtumat, callback) {
    return db.query(
      'update tilitapahtumat set idTilitapahtumat=?,paivamaara=?, tapahtuma=?, summa=?, idKortti=?, idTili=? where idtilitapahtumat=?',
      [tilitapahtumat.idTilitapahtumat, tilitapahtumat.paivamaara, tilitapahtumat.tapahtuma, tilitapahtumat.summa, tilitapahtumat.idKortti, tilitapahtumat.idTili, idtilitapahtumat],
      callback
    );
  }
};
module.exports = tilitapahtumat;