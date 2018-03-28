<?php

require "dbcon.php";
$room=$_GET['room'];
$new=$_GET['new'];
$id =$_GET['id'];
if ($room =="4"){
$query ="UPDATE R1 SET Stt='$id',Var='$new' WHERE Stt ='$id'";
}
if ($room =="5"){
$query ="UPDATE R2 SET Stt='$id',Var='$new' WHERE Stt ='$id'";
}
if ($room =="1"){
$query ="UPDATE Room1 SET Stt='$id',New='$new' WHERE Stt ='$id'";
}
if ($room =="2"){
$query ="UPDATE Room2 SET Stt='$id',New='$new' WHERE Stt ='$id'";
}
if ($room =="3"){
$query ="UPDATE Sound SET Stt='$id',New='$new' WHERE Stt ='$id'";
}
if(mysqli_query($connect,$query))
{
    echo "1";
}
else {
echo "0";
}

?>