const n = 6
let arr1 = [46, 33, 33 ,22, 31, 50]
let arr2 = [27 ,56, 19, 14, 14, 10]

let result = []
let row = ''
console.log(result)
for(let i=0;i<n;i++){
    row = (arr1[i]|arr2[i]).toString(2).replace(/0/g,' ').replace(/1/g,'#')
    console.log(row)
    while(row.length!=n){
        row = ' ' + row
    }
    result.push(row)
}
console.log(result)