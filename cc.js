const fs = require('fs');
const path = require('path');


const template = `/* 

*/

#include <iostream>
#include <cstdio>
#include "utils/basic-functions.h"

using namespace std;


int main() {
    // Complete the code.
    return 0;
}
`;

const createFile = (baseName) => {
  fs.writeFileSync(
    `${path.resolve(__dirname)}/challenges/${baseName}.cpp`,
    template,
    (err) => {
      if (err) throw err;
    }
  );
};

const createChallenge = () => {
  const args = process.argv.slice(2);
  if (args.length < 1) return console.error('Either no difficulty or challenge name provided.');
  const baseName = args[0];
  createFile(baseName);
};

createChallenge();
