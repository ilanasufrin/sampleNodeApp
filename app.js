var express = require('express');
var app = express();
var cons = require('consolidate');


// assign the underscore engine to .html files
app.engine('html', cons.underscore);

// set .html as the default extension 
app.set('view engine', 'html');
app.set('views', __dirname + '/views');

app.get('/', function(req, res){
  res.render('index', {
    title: 'Consolidate.js'
  });
});

//defines the route /hello.txt
app.get('/hello.txt', function(req, res){
  res.send('Hello World');
});


var server = app.listen(3000, function() {
    console.log('Listening on port %d', server.address().port);
});

//don't forget to talk about installing nodemon globally so we don't have to refresh
//--save adds it to package.json




