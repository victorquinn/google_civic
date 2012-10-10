<?php

/**
 * @file Google Civic Address Block Template.
 */

/**
 * coderev-google_civic
 * I don't think we actually need a title here, since Drupal gives us that
 * for free, right?  i.e. you can just place a block and configure it with
 * a subject and that'll display the title?
 * In any event, if we do add a title here, it should at minimum be enclosed
 * in t().
 * Given that... perhaps we don't really need this theme hook and template?
 */
?>

<h3>Find your polling place!</h3>
<?php print $address_form; ?>
