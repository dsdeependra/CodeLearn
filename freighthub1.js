const numbers = [2, 4, 6, 8, 9, 15];

// Expected result: [4, 16, 64]

// Sorting numbers ascending.


startingArray.sort((n1, n2) => n1 > n2);

const firstNumber = startingArray[0];
const lastNumber = startingArray[startingArray.length - 1];

const resultArray = [];
let number = firstNumber;
while (number <= lastNumber) {
  if (-1 !== startingArray.indexOf(number)) {
    resultArray.push(Math.pow(number, 2));
  }
  number = number * 2;
}

console.log(resultArray);