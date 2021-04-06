
let a = '';
for (let i = 0; i < 100; i+= 1) {
  a += `| ${i}               | ×           | ×         | [link](/${i}.cpp)  | [link](https://projecteuler.net/problem=${i}) |\n`
}
console.log(a);