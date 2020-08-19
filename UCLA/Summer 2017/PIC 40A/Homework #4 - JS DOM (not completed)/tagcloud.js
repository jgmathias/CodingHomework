var uniquearray;
var countarray;
var sizearray;
var cloud;

function makeCloud()
{
	var text = document.getElementById("tags");
	var textarray = text.split(" ");
	textarray.sort;
	
	var j = 0;
	uniquearray.push(textarray[0]);
	countarray.push(1);
	for(var i = 1; i < textarray.length(); i++)
	{
		if(textarray[i] == textarray[i-1])
		{
			countarray[j]++;
		}
		else
		{
			j++;
			uniquearray.push(textarray[i]);
			countarray.push(1);
		}
	}
	
	var max = countarray[0];
	for(var k = 1; k < countarray.length(); k++)
	{
		if(countarray[k] > max)
		{
			max = countarray[k];
		}
	}
	
	cloud = document.createElement("div");
	
	for(var l = 0; l < uniquearray.length(); l++)
	{
		sizearray.push((Math.ceil(countarray[l] / max * 20) + 15) + "pt");
	}
}

function saveCloud()
{
	
}

function loadCloud()
{
	
}

function clearArea()
{
	
}
