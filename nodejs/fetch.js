const fetch = (url) => {
  // Return a promise to our data
  return new Promise ((resolve, reject) => {
    const lib = (url.startsWith('https')) ? require('https') : require('http');

    let message = [];

    lib.get(url, (response) => {
      response.setEncoding('utf-8'); // get plain strings instead of Buffer objects

      if (response.statusCode < 200 || response.statusCode > 299)
        reject(new Error(`The request faild with ${response.statusCode + ": " + response.statusMessage}`));

      response.on('data', chunk => message.push(chunk));

      response.on('end', () => resolve(message.join('')));

      response.on('error', err => reject(err));
    });
  });
};



// A simple test
fetch('https://github.com/')
  .then(console.log)
  .catch(console.log);
