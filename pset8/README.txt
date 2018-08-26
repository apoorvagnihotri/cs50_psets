Mashup

instructions for running -

1. stop any running servers or mysql database by typing the following command in the terminal window.
apache50 stop
mysql50 stop

2. start the apache server using the command provided below
apache50 start ~/workspace/level2phase3/pset8/public

3. start mysql by typing the following command in the terminal
mysql50 start

4. Now open the website by going to the left hand top corner and opening a dropdown menu by clicking "CS50 IDE"
and then clicking "Web Server".

5. A new tab will open and it will contain the website brought together made by me.



More Info:

This project uses google maps and google news to fetch realtime news of differnet locations in this world to preview them
in the map based on the loction we want to see the news of.

In this project I used a number of technologies to make this project work.
some of them being, google maps, typehead.js, underscore.js and many more.
This project is more inclined to bring together differnet technologies to make things work.

In this project first we used the data to be fed into the database for identifing which pin code reffered 
which lattitute and longitude.
I used US and IN's data files to feed data into the database.

pset8/bin/import:
For feeding the data into the database I implemented a file in php called, "import", which takes 
1 argument as the file name of the data file we are trying to import into the database.

pset8/config.json:
This file contains the configuration of the database we are using to store the places on the map.
It contains the username, password, database name and the host. This file helps the website to be more modular and easy 
to change in the event of changing of database, username or the host.

pset8/pset8.sql:
This is a file containg mysql commands provided by the cs50 staff to setup the table places in the database in accordance
with the format in the file provided by The GeoNames.
###The GeoNames geographical database covers all countries 
and contains over eleven million placenames that are available for download free of charge.###

After loding the data into the database, we then move on to the implementation of search using typehead.js and underscore.js.
search.php is called by scripts.js when we type in a string in the search box.
It returns an array of places that match the search query

pset8/public/js/scripts.js:
This file is the main file of the entire website. This file helps the working of the website and tells the website 
when to perform what function. This file contains the scripts required for the loading of google maps and it tells what functions
to call when the maps are done loading. This file helps in adding lables to the maps upon draging and zooming. This file 
calls articles.php to provide with articles related to the geolocation of the markers. This file helps in removing the markers 
when there is change in focus of the map canvas.

pset8/public/search.php:
We first require config.php in search.php to connect to our database and then we search the database for a match in the
stored values with the provided query. search.php returns an array of the places that matched the 
search query.

pset8/public/articles.php:
This file is used to fetch data from the google news servers using a pin that is provided to this file using get method.
This file returns a json data format which is then read and rendered by using the technology underscore.js

pset8/includes/helper.php:
pset8/includes/config.php:
pset8/vendor/library50-php-5/CS50/CS50.php:
These file are included by the CS50's staff for easy implementation of the project. These files include custom made fuctions for the use of
students to make it easier for them to understand the basic ideas regarding web develepment. These files contain the functionality of functions
lookup(&geo)[for getting rss of a perticular geo pin code.], CS50::query [for making it easier to perform mysql fuctions on CS50 IDE], etc.
These files hide the most basic functionality from the students, but I tried to understand it as much I could.

This completes the intro to the main files that this project encompasses and uses.