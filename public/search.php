<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];

    // TODO: search database for places matching $_GET["geo"], store in $places
    
    // saving the _GET variable as a local variable.
    $geo = $_GET["geo"];
    
    // ran few commands on sql to add full text index to place_name and postal_code.
    /** ALTER TABLE  table_name  
      * FULLTEXT(column_name1, column_name2,…)
      */
    // getting the places that match the first 4 (full text index default) words of the place or zip and saving in places.
    $places = CS50::query("SELECT * FROM places WHERE MATCH(postal_code, place_name) AGAINST (? IN BOOLEAN MODE)", ('+' . $geo . '*'));

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>