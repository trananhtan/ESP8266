<?php
require "dbcon.php";
$query1 ="SELECT * FROM `Room1`";
$data1 =mysqli_query($connect,$query1);
while($row =mysqli_fetch_assoc($data1))
{
    echo $row['Ten']; 
    echo"="; 
    echo $row['App'] ;
    echo "<br>";
}
$query2 ="SELECT * FROM `Room2`";
$data2 =mysqli_query($connect,$query2);
while($row =mysqli_fetch_assoc($data2))
{
    echo $row['Ten']; 
    echo"="; 
    echo $row['App'] ;
    echo "<br>";
}
$query3 ="SELECT * FROM `Sound`";
$data3 =mysqli_query($connect,$query3);
while($row =mysqli_fetch_assoc($data3))
{
    echo $row['Ten']; 
    echo"="; 
    echo $row['App'] ;
    echo "<br>";
}
?>