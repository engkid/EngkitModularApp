window.AlipayH5Share||function(){var e,t={},n={title:"",imgUrl:"",link:"",desc:"",fromMeta:!1,ready:!1},r={title:!1,link:!1,imgUrl:!1,desc:!1},i={init:function(e){var t=this;t.strict="undefined"==typeof e||!!e,t.collectLink(),t.collectTitle(),t.collectDesc(),t.collectThumbnail()},collectLink:function(){var e=this,t=document.querySelector('meta[name="Alipay:link"]');t&&t.getAttribute("content")&&(n.fromMeta=!0,n.link=t.getAttribute("content")),r.link=!0,e.collectReady()},collectTitle:function(){var e=this,t=document.querySelector('meta[name="Alipay:title"]');if(t&&t.getAttribute("content"))r.title=!0,n.title=t.getAttribute("content"),n.fromMeta=!0,e.collectReady();else if("mp.weixin.qq.com"===window.location.hostname&&"undefined"!=typeof msg_title&&msg_title)r.title=!0,n.title=e.htmlDecode(msg_title),e.collectReady();else if(document.title&&""!==document.title.trim())n.title=e.contentTidy(document.title),r.title=!0,e.collectReady();else if(document.getElementsByTagName("H1").length>0&&document.getElementsByTagName("H1")[0].textContent.length>0){var i=e.nodeStrFliter(document.getElementsByTagName("H1")[0]);e.getStrLen(i)<=64&&i.length>0&&(n.title=i,r.title=!0,e.collectReady())}},collectThumbnail:function(){var t=this,i=document.querySelector('meta[name="Alipay:imgUrl"]');if(i&&i.getAttribute("content"))r.imgUrl=!0,n.imgUrl=t.getAbsoluteUrl(i.getAttribute("content")),n.fromMeta=!0,t.collectReady();else if("mp.weixin.qq.com"===window.location.hostname&&"undefined"!=typeof msg_cdn_url&&msg_cdn_url.match(/^http(s?):\/\/.*$/g))r.imgUrl=!0,n.imgUrl=msg_cdn_url,t.collectReady();else if(r.imgUrl=!1,t.collectReady(),e=Array.prototype.slice.call(document.images),t.findImgUrl(1e4,128e4),t.strict||(""==n.imgUrl&&t.findImgUrl(2500,1e4),""==n.imgUrl&&t.findImgUrl(1024,2500)),""==n.imgUrl){var l=document.querySelector('link[type="image/x-icon"]');l&&l.getAttribute("href")&&(r.imgUrl=!0,n.imgUrl=t.getAbsoluteUrl(l.getAttribute("href")),t.collectReady())}},findImgUrl:function(t,l){var c=i;if(0===e.length)return r.imgUrl=!0,void c.collectReady();var o=99999,d=99999;if(e.length>0&&!r.imgUrl)for(var a=0;a<e.length;a++){var u=e[a];c.isHidden(u)||c.isBanner(u)||(u.complete||u.natureWidth)&&u.naturalHeight*u.naturalWidth>=t&&u.naturalHeight*u.naturalWidth<l&&(u.y>60&&u.y<o||u.y<=60&&u.y>o||u.y===o&&u.x<d)&&(n.imgUrl=u.src,o=u.y||0,d=u.x||0,r.imgUrl=!0,c.collectReady())}},collectDesc:function(){var e=this,t=document.querySelector('meta[name="Alipay:desc"]');if(t&&t.getAttribute("content")&&(r.desc=!0,n.desc=t.getAttribute("content"),n.fromMeta=!0,e.collectReady()),!r.desc&&"mp.weixin.qq.com"===window.location.hostname&&"undefined"!=typeof msg_desc&&msg_desc&&(r.desc=!0,n.desc=e.htmlDecode(msg_desc),e.collectReady()),r.desc||e.tarvelPtags(50,2e3),r.desc||e.tarvelPtags(20,50),r.desc||e.travelDocument(document.body,50,2e3),!r.desc){var i=document.querySelector('meta[name="description"]');i&&i.getAttribute("content")&&(n.desc=e.contentTidy(i.getAttribute("content")),n.fromMeta=!0,r.desc=!0,e.collectReady())}if(e.strict||(r.desc||e.travelDocument(document.body,20,50),r.desc||e.tarvelPtags(10,20),r.desc||e.travelDocument(document.body,10,20)),!r.desc){var l=window.location.hostname;void 0!=l&&""!=l&&(n.desc=l,r.desc=!0,e.collectReady())}var c=window.location.href,o=n.desc?n.desc:"",d=280-e.getStrLen(c);d<=e.getStrLen(o)&&d>=0&&(o=e.cutStr(o,Math.floor(d/2))),n.desc=o},collectReady:function(){r.title&&r.imgUrl&&r.link&&r.desc&&(n.ready=!0)},tarvelPtags:function(e,t){var i=this,l=Array.prototype.slice.call(document.getElementsByTagName("P"));if(l.length>0)for(var c=0;c<l.length;c++){var o=l[c];if("undefined"!=typeof o&&"Debug"!=o.id&&!i.isHidden(o)){var d=o.textContent;if(i.getStrLen(d)>=e&&i.getStrLen(d)<t&&(d=i.nodeStrFliter(o,!1)),i.getStrLen(d)>=e&&i.getStrLen(d)<t&&(n.desc=d,r.desc=!0,i.collectReady()),r.desc)break}}},travelDocument:function(e,t,i){if(void 0!=e&&e.hasChildNodes()){var l=this,c=e.childNodes;if(c&&c.length>0)for(var o=0;o<c.length;o++){var d=c[o];if("undefined"!=typeof d){switch(d.nodeType){case 1:l.isHidden(d)||"P"!=d.nodeName&&"SCRIPT"!=d.nodeName&&"STYLE"!=d.nodeName&&"AUDIO"!=d.nodeName&&"VIDEO"!=d.nodeName&&l.travelDocument(d,t,i);break;case 3:var a=d.nodeValue;l.getStrLen(a)>=t&&l.getStrLen(a)<i&&(a=l.contentTidy(a)),l.getStrLen(a)>=t&&l.getStrLen(a)<=i&&(n.desc=a,r.desc=!0,l.collectReady())}if(r.desc)break}}}},getStrLen:function(e){return e.replace(/[^\x00-\xff]/g,"xx").length},cutStr:function(e,t){for(var n=0,r=0;r<e.length;r++){var i=e.charAt(r);if(n+=encodeURI(i).length>2?1:.5,n>=t){var l=n==t?r+1:r;return e.substr(0,l)}}},getAbsoluteUrl:function(e){var t=document.createElement("A");return t.href=e,e=t.href},getCurrentStyle:function(e,t){return window.getComputedStyle?window.getComputedStyle(e,null).getPropertyValue(t):e.currentStyle?e.currentStyle[t]:null},isHidden:function(e){var t=i,n=void 0!=e&&void 0!=e.nodeType&&"1"==e.nodeType&&("none"==t.getCurrentStyle(e,"display")||"hidden"==t.getCurrentStyle(e,"visibility"));return!!n||void 0!=e.parentNode&&t.isHidden(e.parentNode)},isBanner:function(e){var t=i,n=void 0!=e&&void 0!=e.nodeType&&"1"==e.nodeType&&t.matchKeyword([e.className,e.id],["banner","baner"]);return!!n||void 0!=e.parentNode&&t.isBanner(e.parentNode)},matchKeyword:function(e,t){e=e||[],t=t||[];for(var n=0;n<e.length;n++)for(var r=0;r<t.length;r++)if((e[n]||"").indexOf(t[r])>-1)return!0;return!1},getType:function(e){return Object.prototype.toString.call(e).replace(/\[object (\w+)\]/,"$1").toLowerCase()},htmlDecode:function(e){var t=document.createElement("div");return t.innerHTML=e,t.innerText||t.textContent},nodeStrFliter:function(e,t){t=t||!0;var n=this,r=e.cloneNode(!0);return t&&Array.prototype.forEach.call(r.querySelectorAll("img[alt]"),function(e){e.parentNode.replaceChild(document.createTextNode(e.alt),e)}),Array.prototype.forEach.call(r.querySelectorAll("script,style,link"),function(e){e.parentNode.replaceChild(document.createTextNode(""),e)}),r=n.contentTidy(r.textContent)},contentTidy:function(e){return e.replace(/\s{4}/g," ").replace(/(\r|\n)/g,"").trim()}};t.getShareContent=function(e){return e="undefined"==typeof e||!!e,i.init(e),JSON.stringify(n)},document.addEventListener("JSPlugin_AlipayH5Share",function(e){var t="undefined"==typeof e.strict||!!e.strict;window.AlipayJSBridge&&e.clientId&&(i.init(t),window.AlipayJSBridge&&e.clientId&&setTimeout(function(){i.init(t),AlipayJSBridge.callback(e.clientId,n)},0),AlipayJSBridge.callback(e.clientId,n))}),window.AlipayH5Share=t}();
