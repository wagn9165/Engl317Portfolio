<?php include('server.php')?>

<!------------- HTML ------------->
<!DOCTYPE html>
<head>
    <title>Welcome to My Health Portal</title>
</head>

<body>
	<div
		<h1>View Charges</h1>
	</div>
	
	<form method="post" action="DoctorPortalCharges.php">
		<?php include('errors.php'); ?>
		<label>PID</label>
		<select name = "pid"> <br>
			<option>Select</option>;
			<?php			
			$did = $_SESSION['did'];
			$query = "SELECT * FROM SSDD WHERE DoctorID = '$did';";
			$result = mysqli_query($db3, $query);		
			
			while($row = mysqli_fetch_assoc($result))
			{
			$prod_name = $row['PatientID'];
				echo "<option value='$prod_name'>$prod_name</option>";
			}
			?>
		</select> <br>
	
		<div>
			<button type="submit" class="btn" name="select_charges">Submit</button>
		</div>
	</form>
	<p>
			<a href="DoctorPortalIndex.php">Back</a>
	</p>
</body>
</html>