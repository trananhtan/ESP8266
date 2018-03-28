<?php

require "dbcon.php";
$room=$_GET['room'];
$new=$_GET['new'];
$id =$_GET['id'];

if ($room =="1"){
$query ="UPDATE Room1 SET Stt='$id',App='$new' WHERE Stt ='$id'";
}
if ($room =="2"){
$query ="UPDATE Room2 SET Stt='$id',App='$new' WHERE Stt ='$id'";
}
if ($room =="3"){
$query ="UPDATE Sound SET Stt='$id',App='$new' WHERE Stt ='$id'";
}
if(mysqli_query($connect,$query))
{
    echo "1";
}
else {
echo "0";
}

?>