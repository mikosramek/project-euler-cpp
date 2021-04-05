
let a = '';
for (let i = 0; i < 100; i+= 1) {
  a += `| ${i}               | ×           | ×         | [here](/${i}.cpp) |\n`
}
console.log(a);