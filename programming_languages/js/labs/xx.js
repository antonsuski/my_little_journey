// Arrays
let arr = [
  {type : "fruit", name : "banana", weight: 100}, {type : "vegetable", name : "potato", weight: 50},
  {type : "vegetable", name : "eggplant", weight: 300}
];
let num_arr = [1,1,1,1,1];
let arr_arr = [[1,1],[2,2],[3,3]];

arr.forEach(i => console.log(i));
console.log("filetered:", arr.filter(i => i.type == "fruit"));
console.log("mapped:", arr.map(i => i.name));
console.log("filtered and mapped:", arr.filter(i => i.type == "vegetable").map(i => i.name));
console.log("reduced:", arr.reduce((a,b) => {console.log("a:",a.weight,"|b:", b.weight);return {weight:a.weight + b.weight};}));
console.log(num_arr.reduce((a,b) =>{console.log("a:",a,"|b:", b); return a + b;}));
console.log(arr_arr.reduce((a, [b,c]) => {console.log("a:", a, "|b:", b, "|c:", c);return a + b + c},0))
//TODO: some + find methods
