char* FastCanvas::buffer() const
{
  return iDiveImageBuffer->buffer();
}

ISize FastCanvas::bufferSize() const
{
  return iDiveImageBuffer->size();
}

Boolean FastCanvas::isAnimationRunning() const
{
  return iAnimationRunning;
}

HDIVE FastCanvas::diveHandle() const
{
  return iDiveHandle;
}



