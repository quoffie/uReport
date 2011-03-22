<?php
/**
 * @copyright 2011 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Ticket $this->ticket
 */
?>
<table>
	<tr><td><label for="department_id">Department</label></td>
		<td><select name="department_id" id="department_id">
				<option></option>
				<?php
					$assignedPerson = $this->ticket->getAssignedPerson()
						? $this->ticket->getAssignedPerson()
						: $_SESSION['USER']->getPerson();

					$currentDepartment = $assignedPerson->getDepartment()
						? $assignedPerson->getDepartment()
						: $_SESSION['USER']->getDepartment();

					$list = new DepartmentList();
					$list->find();
					foreach ($list as $department) {
						$name = View::escape($department->getName());
						$selected = $department->getId()==$currentDepartment->getId()
							? 'selected="selected"'
							: '';
						echo "<option value=\"{$department->getId()}\" $selected>$name</option>";
					}
				?>
			</select>
		</td>
	</tr>
	<tr><td><label for="assignedPerson_id">Person</label></td>
		<td><select name="assignedPerson_id" id="assignedPerson_id">
			<?php
				$name = View::escape($assignedPerson->getFullname());
				echo "<option value=\"{$assignedPerson->getId()}\">$name</option>";

				foreach ($currentDepartment->getUsers() as $user) {
					$name = View::escape($user->getPerson()->getFullname());
					echo "<option value=\"{$user->getPerson_id()}\">$name</option>";
				}
			?>
			</select>
		</td>
	</tr>
</table>
<div><label for="notes">Comment about the assignment</label></div>
<div><textarea name="notes" id="notes" rows="3" cols="50"></textarea></div>