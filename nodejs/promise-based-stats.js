const fs = require('fs');

// Returns a Promise for the stats information for one file
const stats = (file) => {
  return new Promise((resolve, reject) => {
    fs.stat(file, (err, data) => {
      if (err) return reject(err)
      resolve(data)
    });
  });
};

// Returns a Promise to an array of file stats Promise objects
const filesFromDir = (dir) => {
  return new Promise((resolve,reject) => {
    fs.readdir(dir,(err,files) => {
      if (err) return reject(err)
      resolve(files.map(stats));
    });
  });
}

filesFromDir('.')
.then(resolvers => Promise.all(resolvers))
.then(data => console.log(data))
.catch(err => console.log(err));

// TODO Write again using generators: https://github.com/tj/co
// TODO Write again using async / await
