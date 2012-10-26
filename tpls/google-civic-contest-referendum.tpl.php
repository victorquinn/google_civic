<?php
/**
 * @file
 * Google Civic Contest Referendum Template
 *
 * Available variables:
 * - $title: The title for the fieldset
 * - $subtitle: The subtitle
 * - $details: Link to more details
 */
?>

<fieldset class='collapsible collapsed google-civic-referendum'>
   <legend><span class='fieldset-legend'><?= $title ?></span></legend>
   <div class='fieldset-wrapper'>
     <p><span class="google-civic-referendum-subtitle"><?= $subtitle ?></span></p>
     <p><span class="google-civic-referendum-details-link"><?= $details ?></span></p>
   </div>
</fieldset>
