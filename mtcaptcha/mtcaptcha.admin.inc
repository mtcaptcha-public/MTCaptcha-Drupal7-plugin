<?php

/**
 * @file
 * Provides the MTCaptcha administration settings.
 */
function mtcaptcha_admin_settings() {
  $form['common'] = array(
    '#type' => 'fieldset',
    '#title' => t('MTCaptcha Common Settings'),
    '#description' => t('<b>You have to <a href="@url" target="blank" rel="external">register your domain</a> first, get the private key from MTCaptcha and save it below.</b>'
    , array('@url' => 'https://www.mtcaptcha.com/pricing/')),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );  

  $form['common']['mtcaptcha_private_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Private key'),
    '#default_value' => variable_get('mtcaptcha_private_key', ''),
    '#maxlength' => 128,
    '#description' => t('The private key given to you when you <a href="@url">register for mtcaptcha</a>.', array('@url' => 'https://admin.mtcaptcha.com/signup/profile?plantype=A')),
    '#required' => TRUE,
  );

  $form['common']['mtcaptcha_enablecaptcha'] = array(
    "#type" => "select",
    "#title" => t("Enable MTCaptcha for"),
    "#options" => array(
      "all" => t("All Users"),
      "login" => t("Logged In Users"),
      "logout" => t("Logged Out Users"),      
    ),    
    "#default_value" => variable_get('mtcaptcha_enablecaptcha', "all"),
    "#description" => t('<br> The MTCaptcha will be embedded in Login Form and
    Reset Password Form <br>even though the Enable MTCaptcha is selected for logged  in users. If needed <br>we can disable MTCaptcha for these forms by choosing below options.')
  );
  $form_ids = array(
    'user_login' => t('Login Form'),
    'user_register_form' => t('Registration Form'), 
    'user_pass' => t('Lost Password Form'),
    'user_profile_form' => t('Change Password Form'),
    'comment_node_article_form' => t('Comment Form'),
    'contact_site_form' => t('Contact Form')
  );
  $form['common']['mtcaptcha_enable'] = array(
    '#title' => t('MTCaptcha is applied for'),
    '#type' => 'checkboxes',
    '#default_value' => variable_get('mtcaptcha_enable', array_keys($form_ids)),
    '#description' => t('Please enable MTCaptcha for above forms'),
    '#options' => $form_ids,
  );

  $form['common']['mtcaptcha_other_enable'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Forms to enable'),
    '#default_value' => variable_get('mtcaptcha_other_enable', ''),
    '#description' => t('Please give other form ids mtcaptcha should be enabled'),
    '#maxlength' => 400,
  );

  $form['common']['show_captcha_label_form'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Captcha label in the form'),
    '#default_value' => variable_get('show_captcha_label_form', FALSE),
    '#description' => t('Show or Hide Captcha Label in the forms'), 
    '#attributes' => array(
      'class' => array('captcha-label'), 
    )   
  );


  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('MTCaptcha Basic Options'),
    '#description' => t('<b>You have to <a href="@url" target="blank" rel="external">register your domain</a> first, get the site key from MTCaptcha and save it below.</b>'
    , array('@url' => 'https://www.mtcaptcha.com/pricing/')),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['general']['mtcaptcha_site_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Site key'),
    '#default_value' => variable_get('mtcaptcha_site_key', ''),
    '#maxlength' => 40,
    '#description' => t('The site key given to you when you <a href="@url">register for mtcaptcha</a>.', array('@url' => 'https://admin.mtcaptcha.com/signup/profile?plantype=A')),
    // '#required' => TRUE,
  );
  
  $form['general']['mtcaptcha_theme'] = array(
    '#type' => 'select',
    '#title' => t('Theme'),
    '#description' => t('Defines which theme to use for mtcaptcha.'),
    '#options' => array(
      'standard' => t('standard'),
      'overcast' => t('overcast'),
      'neowhite' => t('neowhite'),
      'goldbezel' => t('goldbezel'),
      'blackmoon' => t('blackmoon'),
      'darkruby' => t('darkruby'),
      'touchoforange' => t('touchoforange'),
      'caribbean' => t('caribbean'),
      'woodyallen' => t('woodyallen'),
      'chrome' => t('chrome'),
      'highcontrast' => t('highcontrast'),
    ),
    '#default_value' => variable_get('mtcaptcha_theme', 'standard'),
  );
  $form['general']['mtcaptcha_language'] = array(
    '#type' => 'select',
    '#title' => t('Language'),
    '#description' => t('Defines which Language to use for mtcaptcha.'),
    '#options' => array(
      'en' => t('English(en)'),
      'ar' => t('Arabic(ar)'),
      "af" => t("Afrikaans(af)"),
      "am" => t("Amharic(am)"),
      "hy" => t("Armenian(hy)"),
      "az" => t("Azerbaijani(az)"),
      "eu" => t("Basque(eu)"),
      "bn" => t("Bengali(bn)"),
      "bg" => t("Bulgarian(bg)"),
      "ca" => t("Catalan(ca)"),
      "zh-hk" => t("Chinese (Hong Kong)(zh-HK)"),
      "zh" => t("Chinese(zh)"),
      "hr" => t("Croatian(hr)"),
      "cs" => t("Czech(cs)"),
      "da" => t("Danish(da)"),
      "nl" => t("Dutch(nl)"),
      "en" => t("English"),
      "et" => t("Estonian(et)"),
      "fil" => t("Filipino(fil)"),
      "fi" => t("Finnish(fi)"),
      "fr" => t("French(fr)"),
      "gl" => t("Galician(gl)"),
      "ka" => t("Georgian(ka)"),
      "de" => t("German(de)"),
      "el" => t("Greek(el)"),
      "gu" => t("Gujarati(gu)"),
      "iw" => t("Hebrew(iw)"),
      "hi" => t("Hindi(hi)"),
      "hu" => t("Hungarain(hu)"),
      "is" => t("Icelandic(is)"),
      "id" => t("Indonesian(id)"),
      "it" => t("Italian(it)"),
      "ja" => t("Japanese(ja)"),
      "kn" => t("Kannada(kn)"),
      "ko" => t("Korean(ko)"),
      "ko" => t("Korean(ko)"),
      "lv" => t("Latvian(lv)"),
      "lt" => t("Lithuanian(lt)"),
      "ms" => t("Malay(ms)"),
      "ml" => t("Malayalam(ml)"),
      "mr" => t("Marathi(mr)"),
      "mn" => t("Mongolian(mn)"),
      "no" => t("Norwegian(no)"),
      "fa" => t("Persian(fa)"),
      "pl" => t("Polish(pl)"),
      "pt" => t("Portuguese(pt)"),
      "ro" => t("Romanian(ro)"),
      "ru" => t("Russian(ru)"),
      "si" => t("Sinhalese(si)"),
      "sr" => t("Serbian(sr)"),
      "sk" => t("Slovak(sk)"),
      "sl" => t("Slovenian(sl)"),
      "es" => t("Spanish(es)"),
      "sw" => t("Swahili(sw)"),
      "sv" => t("Swedish(sv)"),
      "ta" => t("Tamil(ta)"),
      "te" => t("Telugu(te)"),
      "th" => t("Thai(th)"),
      "tr" => t("Turkish(tr)"),
      "uk" => t("Ukrainian(uk)"),
      "ur" => t("Urdu(ur)"),
      "vi" => t("Vietnamese(vi)"),
      "zu" => t("Zulu(zu)")
    ),
    '#default_value' => variable_get('mtcaptcha_language', 'en'),
  );
  $form['general']['mtcaptcha_widgetsize'] = array(
    '#title' => t('Captcha Widget size'),
    '#type' => 'select',
    '#options' => array(
      'standard' => t('Standard'),
      'mini' => t('Modern Mini'),
    ),
    '#default_value' => variable_get('mtcaptcha_widgetsize'),
    '#description' => t('Defines which widgetsize to use for mtcaptcha.'),
  );
  

  $form['advanced'] = [
    '#type' => 'fieldset',
    '#title' => t('MTCaptcha Advanced Options'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,    
  ];

  $form['advanced']['custom_config_enable'] = [
    '#title' =>  t('Enable custom MTCaptcha configuration '),
    '#type' => 'checkbox',
    '#default_value' => variable_get('custom_config_enable'),
    '#description' => t('Provides the custom configuration to render the MTCaptcha in your forms.<br/> 
                        1. You have to <a href="https://www.mtcaptcha.com/pricing/" target="blank" rel="external">register your domain</a> and get your required keys.<br/>
                        2. Visit <a href="http://service.mtcaptcha.com/mtcv1/demo/" target="blank" rel="external">MTCaptcha demo page</a> to customize 
                        the MTCaptcha configuration.<br/> 
                        3. Under Basic Options, Proivde your site key in the Sitekey field. <br/>
                        4. Customize the <b>Basic Options</b>, <b>Custom Style</b> and <b>Custom Language</b>.<br/>
                        5. Click on Apply button to view the changes. <br/>
                        6. If the changes are looks good, 
                        then copy the snippet located inside the <b>script</b> tag under <b>Embed Snippet</b> tab.
                        <br/>
                        7. Paste the copied snippet to the below textbox. <br/> '),
    '#attributes' => array(
          'class' => array('captcha-label'), 
    )    
  ];

  $form['advanced']['custom_config_setting'] = [
    '#default_value' => variable_get('custom_config_setting'),
    '#required' => FALSE,
    '#type' => 'textarea',
    '#attributes' => array('placeholder' => t("var mtcaptchaConfig = {
      'sitekey': 'YOUR SITE KEY',
      'widgetSize': 'mini',
      'lang': 'en',
      'autoFormValidate': true,
      'loadAnimation': true,
     };
   (function(){var mt_service = document.createElement('script');mt_service.async = true;mt_service.src = 'https://service.mtcaptcha.com/mtcv1/client/mtcaptcha.min.js';(document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(mt_service);
   var mt_service2 = document.createElement('script');mt_service2.async = true;mt_service2.src = 'https://service2.mtcaptcha.com/mtcv1/client/mtcaptcha2.min.js';(document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(mt_service2);}) ();"),) 
  ];
  return system_settings_form($form);
}
?>