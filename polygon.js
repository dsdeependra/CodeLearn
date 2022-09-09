function countInArray(array, number) {
    var count = 0;
    for (var i = 0; i < array.length; i++) {
        if (parseInt(array[i]) === number) {
            count++;
        }
    }
    return count;
}

var path = './polygons.txt';
var fs  = require("fs");
fs.readFile(path, function(err, f){
    var array = f.toString().split('\n');
    var trianglesArray = [];
    var rectanglesArray = [];
    var squaresArray = [];
    var othersArray = [];

    for(var i= 0; i < array.length ;i++)
    {
        var item  = array[i];
        var lines =  item.split(',');
        var length = lines.length;

        switch(length)
        {
            case 3 :
            var a = parseInt(lines[0]);
            var b = parseInt(lines[1]);
            var c = parseInt(lines[2]);
            if (((a + b) > c) && ((a + c) > b) && ((b + c) > a)) {
                trianglesArray.push(item); 
            } else { 
                othersArray.push(item);
            }
            break;

            case 4 :

            var a = parseInt(lines[0]);
            var b = parseInt(lines[1]);
            var c = parseInt(lines[2]);
            var d = parseInt(lines[3]);

            var result = lines.reduce(function( accumlative, currentLine) {
                return parseInt(currentLine)  === a;
            });
            
            if(result)
            {
                squaresArray.push(item);
                break;
            }
            else 
            if(((countInArray(lines, a) == 2) && (countInArray(lines, b) == 2))
            ||  ((countInArray(lines, a) == 2) && (countInArray(lines, c) == 2)) 
            ||  ((countInArray(lines, a) == 2) && (countInArray(lines, d) == 2)) 
            ||  ((countInArray(lines, b) == 2) && (countInArray(lines, c) == 2)) 
            ||  ((countInArray(lines, b) == 2) && (countInArray(lines, d) == 2)) 
            ||  ((countInArray(lines, c) == 2) && (countInArray(lines, d) == 2)) ) 
            {  rectanglesArray.push(item);   } 
            else {
              othersArray.push(item); }
            break;

            default:
            othersArray.push(item);
            break;

        }
    }

    console.log('triangles subsets:');
    console.log(trianglesArray);

    console.log('squares subsets:');
    console.log(squaresArray);
        
    console.log('rectangles subsets:');
    console.log(rectanglesArray);

    console.log('others subsets:');
    console.log(othersArray);

});
