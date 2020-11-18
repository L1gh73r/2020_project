<?php
if (1)
{
    $times = 0;
    $total = 0;
    $average = 0;
    $file_path = "all.txt";
    if (file_exists($file_path))
    {
        $file = fopen($file_path,'r');
        while(!feof($file))
        {
            $content = fgets($file);
            $length = strlen($content);
            if($length == 5)
            {
                global $total;
                $total=$total+1;
            }
            elseif ($length == 15)
            {
                global $times;
                $times=$times+1;
            }
         /*   echo $length;
            echo " ";*/
        }
        fclose($file);
    }
    if ($times == 0)
    {
        $average = 0;
    }
    else
    {
        $average = round($total/$times,3);
    }
    echo "在过去".$times."次猜数中计算机平均每次花费".$average."次猜对答案";
}
?>