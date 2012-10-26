<?php
/**
 * @file
 * Google Civic Contest Candidate Template
 *
 * Available variables:
 * - $title: The title for the fieldset
 * - $candidates: An array of candidates
 */
?>

<fieldset class='collapsible collapsed google-civic-candidate'>
   <legend><span class='fieldset-legend'><?= $title ?></span></legend>
   <div class='fieldset-wrapper'>
     <ul>
     <? foreach ($candidates as $candidate): ?>
       <li class='google-civic-candidate'>
         <p><?= l("{$candidate->name} - {$candidate->party}", $candidate->candidateUrl) ?></p>
       </li>
     <? endforeach; ?>
     </ul>
   </div>
</fieldset>
